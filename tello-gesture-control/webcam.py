import cv2 
from utils import CvFpsCalc
from gestures import *
import threading 

# gesture_detector = GestureRecognition(use_static_image_mode = True)
# gesture_buffer = GestureBuffer()

vid = cv2.VideoCapture(0)
cv_fps_calc = CvFpsCalc(buffer_len = 10)
WRITE_CONTROL = False

while(True):
    fps = cv_fps_calc.get()
    ret, frame = vid.read()

    cv2.imshow('frame', frame)
    number = 0
    # mode = 1
    # debug_image, gesture_id = gesture_detector.recognize(frame, number, mode)
    # gesture_buffer.add_gesture(gesture_id)

    # debug_image = gesture_detector.draw_info(debug_image, fps, mode, number)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

vid.release()

cv2.destroyAllWindows