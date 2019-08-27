import tweepy
import tensorflow as tf
from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer

#Twitter credentials for the app
consumer_key = 'n5INwj4tvH52gqkDx3FjElTgR'
consumer_secret = 'flBsFt7G6WvKIdM86rQoCa07vlM8CkFABODjhvLZ8cP6yxZLa0'
access_key= '1152331933717630976-OeIHJ2YTf857M79uGkoVGSQDp7TlKW'
access_secret = '8VC02tF7vYTTzhSbEftoLA8zDrM5fxAYlokxm5a82JJMG'
 
#pass twitter credentials to tweepy
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_key, access_secret)
api = tweepy.API(auth)



start_date = '2019-06-01'
query = "Brexit"
count = 100
num_pages = 50

pages = tweepy.Cursor(api.search, q=query, count=count, include_rts=False, since=start_date).pages(num_pages)



tweets = list()

for page in pages:
    for status in page:
        status = status._json
        if status["lang"] != "en":
            continue
        tweets.append(status["text"])



max_len = 140
embedding_dim = 300
lstm_units = 300
dense_units = 20
max_words = 5000




tokenizer = tf.keras.preprocessing.text.Tokenizer(num_words=max_words)
tokenizer.fit_on_texts(tweets)
sequences = tokenizer.texts_to_sequences(tweets)
X = tf.keras.preprocessing.sequence.pad_sequences(sequences, maxlen=max_len)



analyser = SentimentIntensityAnalyzer()
polarity_scores = [analyser.polarity_scores(tweet) for tweet in tweets]
Y = [int(p["pos"]>p["neg"]) for p in polarity_scores]



model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Embedding(input_dim=max_words, output_dim=embedding_dim))
model.add(tf.keras.layers.LSTM(lstm_units))
model.add(tf.keras.layers.Dense(dense_units))
model.add(tf.keras.layers.Dense(1, activation="sigmoid"))



model.compile(optimizer="adam", loss="binary_crossentropy", metrics=["acc"])
model.fit(X, Y, epochs=1)



class MyStreamListener(tweepy.StreamListener):
    def on_status(self, status):
        print(status.text)
stream = tweepy.Stream(auth=api.auth, listener=MyStreamListener())
rel_stream = stream.filter(track=['Brexit', 'Britain', 'U.K.', 'UK', 'Europe', 'European Union', 'British Exit'], async=True)
rel_stream
















