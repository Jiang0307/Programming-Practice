from keras.datasets import mnist
import matplotlib.pyplot as plt
import random as rand

(train_X, train_y), (test_X, test_y) = mnist.load_data()

num = []

for i in range(10):
    num.append(rand.randint(1,50000))

plt.figure
for i in range(10):
    img = plt.subplot(2,5,i+1)
    img.title.set_text(train_y[num[i]])
    img.imshow(train_X[num[i]],cmap='gray')

    
plt.show()    

