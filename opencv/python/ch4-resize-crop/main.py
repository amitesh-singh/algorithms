import cv2
import numpy as np

img = cv2.imread("../res/lena.png")

print(img.shape)
# returns (512, 512, 3)
#          height, width, channel = BGR
cv2.imshow("show img", img)
                            #width, height
imgResize = cv2.resize(img, (400, 300))
print("resize image: ", imgResize.shape)
cv2.imshow("img resize", imgResize)

# crop the image
imgCropped = img[150:250, 150:250]
cv2.imshow("Cropped image", imgCropped)

# press 'q' to exit
cv2.waitKey(0)
