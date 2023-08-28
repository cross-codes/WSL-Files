import tensorflow as tf

print("\n---------------------\n")
print(tf.version)

# Rank 0 tensors

string = tf.Variable("this is a string", tf.string)
number = tf.Variable(324, tf.int16)
floating = tf.Variable(32.4, tf.float64)
print(
    "Rank of string: ",
    tf.rank(string),
    "\nNumber: ",
    tf.rank(number),
    "\nFloating: ",
    tf.rank(floating),
    "\n",
)

# Non-zero ranked tensors

rank_1_tensor = tf.Variable(["Test", "Ok", "Tim"], tf.string)
rank_2_tensor = tf.Variable(
    [["Test", "Tim", "Cook"], ["Ok", "Second", "Third"]], tf.string
)  # Must be a square and not rectangular

print(
    'Rank of tf.Variable(["Test", "Ok"], tf.string): ',
    tf.rank(rank_1_tensor),
    '\nRank of tf.Variable([["Test", "Tim"], ["Ok", "Second"]], tf.string): ',
    tf.rank(rank_2_tensor),
    "\n",
)

# Shape of tensors

print(
    'Shape of tf.Variable(["Test", "Ok", "Tim"], tf.string): ',
    tf.shape(rank_1_tensor),
    '\nShape of tf.Variable([["Test", "Tim"], ["Ok", "Second"]], tf.string): ',
    tf.shape(rank_2_tensor),
    "\n",
)

# Changing shapes of tensors
tensor1 = tf.ones(
    [1, 2, 3]
)  # Create a shape [1, 2, 3] array with all values initialized to ones
print(
    "tensor1 = ", tensor1
)  # All the values need not be printed, and are shortned by (...)

# [
#      [
#         [1., 1., 1.],
#         [1., 1., 1.]
#      ]
# ]

tensor2 = tf.reshape(tensor1, [2, 3, 1])
print("tensor2 = ", tensor2)

# [
#     [
#         [1.],
#         [1.],
#         [1.]
#     ],
#
#     [
#         [1.],
#         [1.],
#         [1.]
#     ]
# ]

tensor3 = tf.reshape(
    tensor1, [3, -1]
)  # TensorFlow automatically determines the value based on tensor1
print("tensor3 = ", tensor3)

# [
#     [1., 1.],
#     [1., 1.],
#     [1., 1.]
# ]

print("Evaluated tensor1 value: \n", tensor1.numpy())
