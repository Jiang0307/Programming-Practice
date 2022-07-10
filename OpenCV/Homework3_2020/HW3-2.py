import sys
import cv2
import numpy as np
import matplotlib.pyplot as plt

original = cv2.imread('imgblue.jpg')
image = cv2.imread('imgblue.jpg')
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
lower_blue = np.array([85, 50, 50])
upper_blue = np.array([135, 255, 255])
mask = cv2.inRange(hsv, lower_blue, upper_blue)
image[mask>0]=(255, 255, 255)
import sys
import cv2
import numpy as np

image = cv2.imread('imgblue.jpg')
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

lower_blue = np.array([90, 80, 150])
upper_blue = np.array([135, 255, 255])

mask = cv2.inRange(hsv, lower_blue, upper_blue)
image[mask>0]=(255,255,255)

cv2.imshow('original',original)
cv2.imshow('result',image)
cv2.waitKey()
cv2.destroyAllWindows()