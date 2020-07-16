import cv2
import sys
import logging as log
import datetime as dt
from time import sleep

cascPath = "haarcascade_frontalface_default.xml"
faceCascade = cv2.CascadeClassifier(cascPath)
log.basicConfig(filename='webcam.log',level=log.INFO)

video_capture = cv2.VideoCapture(0)
anterior = 0

while True:
    if not video_capture.isOpened():
        print('Unable to load camera.')
        sleep(5)
        pass

    # Capture frame-by-frame
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30)
    )

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        #ht=(y+h)/2
        #wt=(x+w)/2
        #a=x*1.5
        #b=y*1.5
        #a=int(a)
        #b=int(b)
        #ht=int(ht)
        #wt=int(wt)
        x1=(x+w)-x
        y1=((y+h)-y)
        x2=(x1+(x/2))
        y2=(y+(y1/2))
        x2=int(x2)
        y2=int(y2)
        print("frame",x2,y2)
        #print("BOUND",x,y,x+w,y+h)
        cv2.rectangle(frame, (x2, y2), (x2+5, y2+5), (0,0, 255), 2)
        #cv2.circle(frame, (x1,y1),6 (0, 255, 0), -1)



    if anterior != len(faces):
        anterior = len(faces)
        log.info("faces: "+str(len(faces))+" at "+str(dt.datetime.now()))


    # Display the resulting frame
    cv2.imshow('Video', frame)


    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    # Display the resulting frame
    cv2.imshow('Video', frame)

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()
