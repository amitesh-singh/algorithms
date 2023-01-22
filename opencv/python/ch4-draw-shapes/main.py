import cv2 as cv2
import numpy as np

# use np to create an image filled with zeros
imgGray = np.zeros((512, 512))
print(imgGray.shape)
cv2.imshow("gray image", imgGray)

# with color BGR888
img = np.zeros((512, 512, 3), np.uint8)
img[:] = 255, 0, 0 #blue image
img[200:300, 200:300] = 0, 255, 0

# draw a line
cv2.line(img, (0, 0), (200, 300), (0, 0, 255), 2)
#cv2.imshow("color image", img)
cv2.line(img, (0, 0), (img.shape[1], img.shape[0]), (255, 255, 255), 2)

#draw rectangle
cv2.rectangle(img, (0, 0), (250, 250), (0, 0, 255), 2)
cv2.rectangle(img, (100, 100), (250, 250), (0, 255, 255), cv2.FILLED)

#draw circle
cv2.circle(img, (350, 200), 50, (255, 255, 0), 3)

#draw text
#cv2.putText(img, "Hey ami", (256, 256), cv2.FONT_ITALIC, 1, (0, 0, 0), 4)
cv2.putText(img, "Hey ami", (256, 256), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 150, 0), 1)

cv2.imshow("color image", img)

cv2.waitKey(0)