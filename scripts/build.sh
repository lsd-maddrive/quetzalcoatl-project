#!/usr/bin/env bash

export CMAKE_PREFIX_PATH=/usr/local/lib/cmake:$CMAKE_PREFIX_PATH
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

cd src/maddrive_ros_shared/third_party/Lslidar_ROS1_driver
git checkout CH64W_V1.0
cd -

if catkin list | grep -q "lslidar_driver"; then
    catkin clean lslidar_driver
fi

catkin build \
    quetzalcoatl-project \
    maddrive_ros_shared \
    ackermann_controller_plugin \
    elp_stereo_camera \
    rtabmap \
    rtabmap_ros \
    ublox \
    cv_bridge \
    stereo_image_proc \
    camera_calibration \
    lslidar_driver \
    realsense2_camera \
    realsense2_description \
    image_geometry \
    hector_gazebo \
    -j$(($(nproc)-2)) \
    --cmake-args \
    -D OpenCV_DIR="/usr/local/lib/cmake/opencv4" \
    -D RTABMAP_SYNC_MULTI_RGBD=ON