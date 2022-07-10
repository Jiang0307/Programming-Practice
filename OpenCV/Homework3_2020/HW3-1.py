from cv2 import cv2
import numpy as np
import matplotlib.pyplot as plt
from scipy import ndimage

def MidPointFilter(img):
   max = ndimage.maximum_filter(img,size=4)
   min = ndimage.minimum_filter(img,size=4)
   midpoint = (max + min) / 2
   return midpoint

img1 = cv2.imread("noise_1.bmp")
img2 = cv2.imread("noise_2.bmp")
img3 = cv2.imread("noise_3.bmp")

mean = cv2.boxFilter(img1,-1,(5,5))
midpoint = MidPointFilter(img2)
median = cv2.medianBlur(img3,5)

plt.figure(figsize=(8,8))
plt.subplot(321), plt.imshow(img1), plt.title("mean filter before")
plt.subplot(322), plt.imshow(mean), plt.title("mean filter after")

plt.subplot(323), plt.imshow(img2), plt.title("midpoint filter before")
plt.subplot(324), plt.imshow(midpoint), plt.title("midpoint filter before")


plt.subplot(325), plt.imshow(img3), plt.title("median filter before")
plt.subplot(326), plt.imshow(median), plt.title("median filter after")

plt.subplots_adjust(hspace=1)
plt.show()

cv2.waitKey()
cv2.destroyAllWindows()