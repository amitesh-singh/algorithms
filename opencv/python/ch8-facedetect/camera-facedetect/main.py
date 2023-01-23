import cv2
import time

# this example shows how to detect faces, eyes and show the FPS on the screen

cap = cv2.VideoCapture(0)
# load the face detector
faceCascade= cv2.CascadeClassifier("../../res/haarcascade_frontalface_default.xml")
eyeCascade=cv2.CascadeClassifier('../../res/haarcascade_eye.xml')

while True:
    start = time.time()

    success, img = cap.read()
    imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    
    faces = faceCascade.detectMultiScale(imgGray,1.1,4)
    for (x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
        roi_gray = imgGray[y: y +h, x: x+w]
        roi_color = img[y: y+h, x: x+ w]
        eyes = eyeCascade.detectMultiScale(roi_gray)
        for (ex, ey, ew, eh) in eyes:
            cv2.rectangle(roi_color, (ex, ey), (ex + ew, ey + eh), (255, 0, 0), 1)

    end = time.time()
    totalTime = end - start
    fps = 1/totalTime
    print("FPS: ", fps)
    cv2.putText(img, f'FPS: {int(fps)}', (20, 70), cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 0, 255), 2)

    cv2.imshow("face detect", img)

    key = cv2.waitKey(1)
    if key == ord('q'):
        break

cap.release()