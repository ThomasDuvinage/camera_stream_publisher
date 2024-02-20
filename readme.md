# camera_stream_publisher 

This ROS node aims to publish images from a given camera that cannot be handle by the default ros image publisher. 

## Install 

```bash
cd cakin_ws/src
git clone https://github.com/ThomasDuvinage/camera_stream_publisher
cd ..
catkin_make 
```

## Run 

```rosrun camera_stream_publisher camera_stream_publisher_node  ```

or 

```roslaunch camera_stream_publisher camera_stream_publisher.launch ```

## Launch File 

```xml

<node pkg="camera_stream_publisher" type="camera_stream_publisher_node" name="camera_stream_publisher"  output="screen">
    <param name="video_source" type="int" value="2" /> 
</node>

```

To find the camera index run :

```bash
v4l2-ctl --list-devices
```