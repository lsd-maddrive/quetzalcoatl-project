#!/usr/bin/env bash

export CMAKE_PREFIX_PATH=/usr/local/lib/cmake/:$CMAKE_PREFIX_PATH
export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH

catkin build \
    quetzalcoatl-project \
    realsense2_camera \
    realsense2_description \
    cv_bridge \
    image_geometry \
    rtabmap \
    rtabmap_ros \
    spatio_temporal_voxel_layer \
    camera_calibration \
    elp_stereo_camera \
    stereo_image_proc \
    ublox \
    maddrive_urdf_tools \
    -j$(($(nproc)-2)) \
    --cmake-args -D OpenCV_DIR="/usr/local/lib/cmake/opencv4" -D RTABMAP_SYNC_MULTI_RGBD=ON