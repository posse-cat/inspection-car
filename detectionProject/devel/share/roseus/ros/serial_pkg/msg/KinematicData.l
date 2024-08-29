;; Auto-generated. Do not edit!


(when (boundp 'serial_pkg::KinematicData)
  (if (not (find-package "SERIAL_PKG"))
    (make-package "SERIAL_PKG"))
  (shadow 'KinematicData (find-package "SERIAL_PKG")))
(unless (find-package "SERIAL_PKG::KINEMATICDATA")
  (make-package "SERIAL_PKG::KINEMATICDATA"))

(in-package "ROS")
;;//! \htmlinclude KinematicData.msg.html


(defclass serial_pkg::KinematicData
  :super ros::object
  :slots (_line_velocity _roll _pitch _yaw ))

(defmethod serial_pkg::KinematicData
  (:init
   (&key
    ((:line_velocity __line_velocity) 0.0)
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    ((:yaw __yaw) 0.0)
    )
   (send-super :init)
   (setq _line_velocity (float __line_velocity))
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   (setq _yaw (float __yaw))
   self)
  (:line_velocity
   (&optional __line_velocity)
   (if __line_velocity (setq _line_velocity __line_velocity)) _line_velocity)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:serialization-length
   ()
   (+
    ;; float64 _line_velocity
    8
    ;; float64 _roll
    8
    ;; float64 _pitch
    8
    ;; float64 _yaw
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _line_velocity
       (sys::poke _line_velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _line_velocity
     (setq _line_velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _roll
     (setq _roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pitch
     (setq _pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get serial_pkg::KinematicData :md5sum-) "2b6ab2dd5908a8a55d4e38931ba25856")
(setf (get serial_pkg::KinematicData :datatype-) "serial_pkg/KinematicData")
(setf (get serial_pkg::KinematicData :definition-)
      "float64 line_velocity
float64 roll
float64 pitch
float64 yaw

")



(provide :serial_pkg/KinematicData "2b6ab2dd5908a8a55d4e38931ba25856")


