import cv2
import numpy as np

img = cv2.imread("../res/lena.png")
cv2.imshow("lena ", img)

imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow("gray image", imgGray)

imgBlur = cv2.GaussianBlur(img, (7, 7), 0)
cv2.imshow("color blur", imgBlur)

imgBlur2 = cv2.GaussianBlur(imgGray, (7, 7), 0)
cv2.imshow("gray blur", imgBlur2)

# to detect edges, we use Canny method
imgCanny = cv2.Canny(img, 100, 100)
cv2.imshow("Canny image", imgCanny)

# lets increase  the threshold values from 100, 100 to 150, 200
imgCanny2 = cv2.Canny(img, 150, 200)
cv2.imshow("Canny2 image", imgCanny2)

# lets say we want to increase the thickness of edges, for that
# we have to use dilate method
kernel = np.ones((5, 5), np.uint8)

imgDilate = cv2.dilate(imgCanny2, kernel, iterations=1)
cv2.imshow("dilate image", imgDilate)

# erode is opposite of dilation
imgErode = cv2.erode(imgDilate, kernel, iterations=1)
cv2.imshow("erode image", imgErode)

# press q to exit
cv2.waitKey(0)
