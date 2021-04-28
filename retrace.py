import cv2
import sys
import logging as log
import datetime as dt
from time import sleep
from math import atan2
from math import degrees
global video_capture
video_capture = cv2.VideoCapture(0)
#while True:
#    if not video_capture.isOpened():
#        print('Unable to load camera.')
#        sleep(5)
#        pass

def trace():
        
        anterior = 0
        degs=0
        rads=0
        cascPath = "haarcascade_frontalface_default.xml"
        faceCascade = cv2.CascadeClassifier(cascPath)
        log.basicConfig(filename='webcam.log',level=log.INFO)


    # Capture frame-by-frame
        ret, frame = video_capture.read()

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = faceCascade.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(40, 40)
        )

        # Draw a rectangle around the faces
        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
            i, j = (x + (x+w)) // 2, (y +(y+h)) // 2
    # Draw a circle in the center of rectangle
            cv2.circle(frame, center=(i,j), radius=3, color=(0,0, 255), thickness=1)
            dy = 360-i
            dx= 640-j
            rads = atan2(dy,dx)
            degs=0
            degs = degrees(rads)
            if degs < 0 :
                degs +=90

        if anterior != len(faces):
            anterior = len(faces)
            #log.info("faces: "+str(len(faces))+" at "+str(dt.datetime.now()))
            log.info("Degree: "+str(degs)+ "\nRadians"+str(rads))

        # Display the resulting frame
        cv2.imshow('Video', frame)


        if cv2.waitKey(1) & 0xFF == ord('q'):
            return(1)
        # Display the resulting frame
        cv2.imshow('Video', frame)
        print("Degrees",degs)
        print("Radians",rads)
        
    # When everything is done, release the capture
while(1):
    trace()
video_capture.release()
cv2.destroyAllWindows()
