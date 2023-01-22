# read from a video file
#cap = cv2.VideoCapture("res/test.mp4")
# read from a web camera, index 0, 1 .. etcs
import cv2

#cap = cv2.VideoCapture("res/test.mp4")
cap = cv2.VideoCapture(0)
cap.set(3, 1020)
cap.set(4, 920)

while True:
    # success - True or False on reading image
    # img - frame read from the video feed
    success, img = cap.read()
    if success:
        cv2.imshow("Video", img)
    # exits on pressing q
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
