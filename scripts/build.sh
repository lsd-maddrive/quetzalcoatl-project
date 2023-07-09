#!/usr/bin/env bash

cd src/maddrive_ros_shared/third_party/Lslidar_ROS1_driver
git checkout CH64W_V1.0
cd -

export CMAKE_PREFIX_PATH=/usr/local/lib/cmake:$CMAKE_PREFIX_PATH
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

catkin clean lslidar_driver
catkin build \
    quetzalcoatl-project \
    elp_stereo_camera \
    rtabmap \
    rtabmap_ros \
    ublox \
    cv_bridge \
    stereo_image_proc \
    camera_calibration \
    maddrive_urdf_tools \
    maddrive_teleop \
    maddrive_worlds \
    lslidar_driver \
    realsense2_camera \
    realsense2_description \
    image_geometry \
    -j$(($(nproc)-2)) \
    --cmake-args -D OpenCV_DIR="/usr/local/lib/cmake/opencv4" -D RTABMAP_SYNC_MULTI_RGBD=ON