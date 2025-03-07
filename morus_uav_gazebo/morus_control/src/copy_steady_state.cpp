/*
 Copyright (c) 2015, Mina Kamel, ASL, ETH Zurich, Switzerland

 You can contact the author at <mina.kamel@mavt.ethz.ch>

 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * Neither the name of ETHZ-ASL nor the
 names of its contributors may be used to endorse or promote products
 derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL ETHZ-ASL BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <morus_control/steady_state_calculation.h>
#include<cmath>
#include<vector>
#include<Eigen/Dense>
#include<Eigen/QR>
#include<Eigen/Eigenvalues>
    
namespace mav_control_attitude {
    using namespace Eigen;
    constexpr int SteadyStateCalculation::kStateSize;
    constexpr int SteadyStateCalculation::kInputSize;
    constexpr int SteadyStateCalculation::kMeasurementSize;
    constexpr int SteadyStateCalculation::kDisturbanceSize;

SteadyStateCalculation::SteadyStateCalculation(const ros::NodeHandle& nh,
                                               const ros::NodeHandle& private_nh)
    : nh_(nh),
      private_nh_(private_nh),
      controller_nh_(private_nh, "controller"),
      initialized_params_(false),
      verbose_(true)
{
}

SteadyStateCalculation::~SteadyStateCalculation()
{
}

void SteadyStateCalculation::initialize(const Eigen::MatrixXd& A,
                                        const Eigen::MatrixXd& B,
                                        const Eigen::MatrixXd& Bd)
{
  Eigen::MatrixXd left_hand_side , razbij_kondicijski_broj;
  left_hand_side.resize(kStateSize + kMeasurementSize, kStateSize + kInputSize);
  razbij_kondicijski_broj =Eigen::MatrixXd::Identity(kStateSize + kInputSize, kStateSize + kInputSize);
  Bd_ = Bd;
  Eigen::MatrixXd C(kMeasurementSize, kStateSize);
  C.setZero();
  C(4 + 2*combined_control_mpc_use_) = 1.0; // measured only the angle
   ROS_INFO_STREAM("Ovo je C " << C << "\n");  
  left_hand_side << A - Eigen::MatrixXd::Identity(kStateSize, kStateSize), B,
      C, Eigen::MatrixXd::Zero(kMeasurementSize, kInputSize);

  //Eigen::CompleteOrthogonalDecomposition<Eigen::MatrixXd> cqr(left_hand_side);

  pseudo_inverse_left_hand_side_ = (left_hand_side.transpose() * left_hand_side + 0*razbij_kondicijski_broj).inverse()
      * left_hand_side.transpose();
  //pseudo_inverse_left_hand_side_  = cqr.pseudoInverse();
  
  for(int i = 0; i <kStateSize + kInputSize ; i++){
    for(int j = 0; j <kStateSize + kMeasurementSize ; j++){
        //ROS_INFO_STREAM("\n " << fabs(pseudo_inverse_left_hand_side_(i,j)) );
        pseudo_inverse_left_hand_side_(i,j) = (fabs(pseudo_inverse_left_hand_side_(i,j)) < 1e-10) ? 0.0 :pseudo_inverse_left_hand_side_(i,j);
    }
    }
  if (verbose_) {
    ROS_INFO_STREAM("Left hand side of steady state calculation: \n" << left_hand_side);
    ROS_INFO_STREAM("pseudo inverse left hand side of steady state calculation: \n" << pseudo_inverse_left_hand_side_);
  }
  JacobiSVD<MatrixXd> svd(pseudo_inverse_left_hand_side_);
    double cond = svd.singularValues()(0) / svd.singularValues()(svd.singularValues().size()-1);
  ROS_INFO_STREAM("!!!!!!!!!!!!!!Kondicijski broj matric je : " << cond);
  initialized_params_ = true;
  ROS_INFO("Linear MPC: Steady State calculation is initialized correctly");
}

void SteadyStateCalculation::computeSteadyState(
    const Eigen::Matrix<double, kDisturbanceSize, 1> &estimated_disturbance,
    const Eigen::Matrix<double, kMeasurementSize, 1> &reference,
    Eigen::Matrix<double, kStateSize, 1>* steadystate_state,
    Eigen::Matrix<double, kInputSize, 1>* steadystate_input)
{
  assert(steadystate_state);
  assert(steadystate_input);
  assert(initialized_params_);
  //ROS_INFO_STREAM("Ovo je referenca " << reference << "\n");
  Eigen::Matrix<double, kStateSize + kInputSize, 1> target_state_and_input;
  Eigen::Matrix<double, kStateSize + kMeasurementSize, 1> right_hand_side;

  target_state_and_input.setZero();
  right_hand_side << (0*(-Bd_) * estimated_disturbance),
                      reference;
  ROS_INFO_STREAM("Referenca je  " << reference << "\n");
  //if(reference(0,0) > 1e-5)
        target_state_and_input = pseudo_inverse_left_hand_side_ * right_hand_side;
        //ROS_INFO_STREAM("Ovo je target sve " << target_state_and_input << "\n");     
    //ROS_INFO_STREAM("Ovo je target state " << target_state_and_input.segment(0, kStateSize) << "\n"); 
        ROS_INFO_STREAM("Ovo je target input " << target_state_and_input.segment(kStateSize, kInputSize) << "\n");   
  if (target_state_and_input.allFinite()){
    *steadystate_state = target_state_and_input.segment(0, kStateSize);
    *steadystate_input = target_state_and_input.segment(kStateSize, kInputSize);
  }
}

}
