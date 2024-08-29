
(cl:in-package :asdf)

(defsystem "serial_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "KinematicData" :depends-on ("_package_KinematicData"))
    (:file "_package_KinematicData" :depends-on ("_package"))
  ))