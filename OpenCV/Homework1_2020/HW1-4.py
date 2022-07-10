def showImage(title, img):
      ishow = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
      plt.imshow(ishow)
      plt.axis('off')
      plt.title(title)
      plt.show()
from cv2 import cv2
import numpy as np
import matplotlib.pyplot as plt
  
dollar = cv2.imread("100-dollars.tif", 0)
r, c = dollar.shape

x = np.zeros((r,c), dtype = np.uint8)
r = np.zeros((r,c,8), dtype = np.uint8)
for i in range(8):
    x = 2**i
    r[:,:,i] = cv2.bitwise_and(dollar, x)
    mask = r[:,:,i] > 0
    r2 = np.copy(r)
    r2[mask] = 255
    #showImage(str(i),r2[:,:,1])

new_img = r2[:,:,5]+r2[:,:,6]+r2[:,:,7]
cv2.imshow('answer',new_img)

cv2.waitKey()
cv2.destroyAllWindows()