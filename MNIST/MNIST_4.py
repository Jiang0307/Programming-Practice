import matplotlib.pyplot as plt
from keras.datasets import mnist
from keras.utils import np_utils
from keras.models import Sequential
from keras.layers.core import Dense

(X_train, y_train), (X_test, y_test) = mnist.load_data()

X_train = X_train.reshape(len(X_train), -1)  # 二维变一维
X_test = X_test.reshape(len(X_test), -1)

X_train = X_train.astype('float32') 
X_test = X_test.astype('float32')

X_train = (X_train ) / 255
X_test = (X_test ) / 255

y_train = np_utils.to_categorical(y_train, num_classes=10)  #one-hot。若原來為5則轉換後為[0. 0. 0. 0. 0. 1. 0. 0. 0. 0.]
y_test = np_utils.to_categorical(y_test, num_classes=10)

#定義model
model = Sequential()
model.add(Dense(300, input_shape=(784,), activation='relu'))  #hidden layer
model.add(Dense(10, activation='sigmoid'))  # output layer

print(model.summary())

model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

history = model.fit(X_train, y_train, epochs=50, batch_size=300, verbose=1, validation_split=0.05)

# 评估
#loss, accuracy = model.evaluate(X_test, y_test)
loss = history.history['loss']
accuracy = history.history['accuracy']

plt.figure()
plt.subplot(211)
plt.plot(loss)
plt.title("loss")
plt.xlabel("epoch")
plt.ylabel("loss")

plt.subplot(212)
plt.plot(accuracy)
plt.title("accuracy")
plt.xlabel("epoch")
plt.ylabel("accuracy")

plt.tight_layout()
# 保存
model.save('model.h5')


'''
import tensorflow as tf
from keras.datasets import mnist
from keras import models
from keras import layers
from keras.utils import to_categorical


(train_images, train_labels), (test_images, test_labels) = mnist.load_data()
fix_train_images = train_images.reshape((60000, 28 * 28)).astype('float32') / 255
fix_test_images = test_images.reshape((10000, 28 * 28)).astype('float32') / 255
fix_train_labels = to_categorical(train_labels)
fix_test_labels = to_categorical(test_labels)

network = models.Sequential()
network.add(layers.Dense(512, activation='relu', input_shape=(28 * 28,)))
network.add(layers.Dense(10, activation='softmax'))
network.compile(optimizer='rmsprop',loss='categorical_crossentropy',metrics=['accuracy'])

result = network.fit(fix_train_images,fix_train_labels,epochs=10,batch_size=500,validation_data=(fix_test_images, fix_test_labels))
test_loss, test_acc = network.evaluate(fix_test_images, fix_test_labels)
print('test_loss:', test_loss)
print('test_acc:', test_acc)

network.save('./keras_model.h5')
'''