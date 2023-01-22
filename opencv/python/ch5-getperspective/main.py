import cv2
import numpy as np

width, height = 250, 350

img = cv2.imread("../res/cards.jpg")

print(img.shape)

p1 = [84, 369]  # red
p2 = [301, 345]  # green
p3 = [354, 652] # blue
p4 = [98, 694]  # white

img2 = img.copy()
cv2.imshow("original image", img2)

pt1 = np.float32([p1, p2, p4, p3])
pt2 = np.float32([[0, 0], [width, 0], [0, height], [width, height]])

#draw a circle on the corner
cv2.circle(img, (p1[0], p1[1]), 5, (0, 0, 255), cv2.FILLED)
cv2.circle(img, (p2[0], p2[1]), 5, (0, 255, 0), cv2.FILLED)
cv2.circle(img, (p3[0], p3[1]), 5, (255, 0, 0), cv2.FILLED)
cv2.circle(img, (p4[0], p4[1]), 5, (255, 255, 255), cv2.FILLED)

matrix = cv2.getPerspectiveTransform(pt1, pt2)
imgOutput = cv2.warpPerspective(img, matrix, (width, height))


cv2.imshow("Cards", img)
cv2.imshow("card ", imgOutput)

cv2.waitKey(0)