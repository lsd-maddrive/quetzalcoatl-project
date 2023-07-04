#!/usr/bin/env bash

export CMAKE_PREFIX_PATH=/usr/local/lib/cmake/:$CMAKE_PREFIX_PATH
# export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH

catkin build \
    quetzalcoatl-project \
    elp_stereo_camera \
    rtabmap \
    rtabmap_ros \
    ublox \
    cv_bridge \
    stereo_image_proc \
    camera_calibration \
    spatio_temporal_voxel_layer \
    maddrive_urdf_tools \
    maddrive_teleop \
    realsense2_camera \
    realsense2_description \
    image_geometry \
    -j$(($(nproc)-2)) \
    --cmake-args -D OpenCV_DIR="/usr/local/lib/cmake/opencv4" -D RTABMAP_SYNC_MULTI_RGBD=ON -DCATKIN_ENABLE_TESTING=False -DCMAKE_BUILD_TYPE=Release