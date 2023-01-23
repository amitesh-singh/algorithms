import cv2

img = cv2.imread("../res/lena.png")

h_img = cv2.flip(img, 0)
v_img = cv2.flip(img, 1)
h_v_img = cv2.flip(img, -1)

cv2.imshow("image", img)
cv2.imshow("horizontal image", h_img)
cv2.imshow("vertical image", v_img)
cv2.imshow("both horizontal and vertical image", h_v_img)

cv2.waitKey(0)
