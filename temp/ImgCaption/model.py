

import tensorflow as tf


class AttentionModel(tf.keras.Model):
    def __init__(self, units):
        super(AttentionModel, self).__init__()
        self.W1 = tf.keras.layers.Dense(units)
        self.W2 = tf.keras.layers.Dense(units)
        self.V = tf.keras.layers.Dense(1)

    def call(self, features, hidden):
        # features -> ?x64x256, hidden -> ?->512
        hidden_with_time_axis = tf.expand_dims(hidden, 1)
        scores = tf.nn.tanh(self.W1(features) + self.W2(hidden_with_time_axis))
        attention_weights = tf.nn.softmax(self.V(scores), axis=1)
        context_vector = attention_weights * features
        context_vector = tf.reduce_sum(context_vector, axis=1)
        return context_vector, attention_weights


class LSTMDecoder(tf.keras.Model):
    def __init__(self, units):
        super(LSTMDecoder, self).__init__()
        num_words = 10000
        embedding_dim = 256
        self.units = units
        self.attention = AttentionModel(units)
        self.embedding_layer = tf.keras.layers.Embedding(num_words, embedding_dim)
        self.lstm = tf.keras.layers.LSTM(units, return_sequences=True, return_state=True,
                    recurrent_initializer='glorot_uniform')
        self.fc1 = tf.keras.layers.Dense(units)
        self.fc2 = tf.keras.layers.Dense(num_words)

    def call(self, x, features, hidden):
        context_vector, attention_weights = self.attention(features, hidden)
        x = self.embedding_layer(x)
        x = tf.concat([tf.expand_dims(context_vector, 1), x], axis=-1)
        output, state, _ = self.lstm(x)
        x = self.fc1(output)
        x = tf.reshape(x, (-1, x.shape[2]))
        x = self.fc2(x)
        return x, state, attention_weights

    def reset_state(self, batch_size):
        return tf.zeros((batch_size, self.units))
