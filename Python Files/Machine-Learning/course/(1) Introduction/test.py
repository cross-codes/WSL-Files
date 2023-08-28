import tensorflow as tf

t = tf.zeros([5, 5, 5, 5])
t = tf.reshape(t, [625])
print(t)
