;; Auto-generated. Do not edit!


(when (boundp 'testboy::person)
  (if (not (find-package "TESTBOY"))
    (make-package "TESTBOY"))
  (shadow 'person (find-package "TESTBOY")))
(unless (find-package "TESTBOY::PERSON")
  (make-package "TESTBOY::PERSON"))

(in-package "ROS")
;;//! \htmlinclude person.msg.html


(intern "*UKNOWN*" (find-package "TESTBOY::PERSON"))
(shadow '*UKNOWN* (find-package "TESTBOY::PERSON"))
(defconstant testboy::person::*UKNOWN* 0)
(intern "*MALE*" (find-package "TESTBOY::PERSON"))
(shadow '*MALE* (find-package "TESTBOY::PERSON"))
(defconstant testboy::person::*MALE* 1)
(intern "*FEMALE*" (find-package "TESTBOY::PERSON"))
(shadow '*FEMALE* (find-package "TESTBOY::PERSON"))
(defconstant testboy::person::*FEMALE* 2)

(defun testboy::person-to-symbol (const)
  (cond
        ((= const 0) 'testboy::person::*uknown*)
        ((= const 1) 'testboy::person::*male*)
        ((= const 2) 'testboy::person::*female*)
        (t nil)))

(defclass testboy::person
  :super ros::object
  :slots (_name _gender _age ))

(defmethod testboy::person
  (:init
   (&key
    ((:name __name) "")
    ((:gender __gender) 0)
    ((:age __age) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _gender (round __gender))
   (setq _age (round __age))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:gender
   (&optional __gender)
   (if __gender (setq _gender __gender)) _gender)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _gender
    1
    ;; uint8 _age
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _gender
       (write-byte _gender s)
     ;; uint8 _age
       (write-byte _age s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _gender
     (setq _gender (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get testboy::person :md5sum-) "aee706d355638a90d939cda4116438f5")
(setf (get testboy::person :datatype-) "testboy/person")
(setf (get testboy::person :definition-)
      "string name
uint8 gender
uint8 age

uint8 uknown=0
uint8 male=1
uint8 female=2

")



(provide :testboy/person "aee706d355638a90d939cda4116438f5")


