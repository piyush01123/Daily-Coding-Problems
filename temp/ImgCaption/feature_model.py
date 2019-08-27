
import tensorflow as tf
import numpy as np
import json
import sklearn
import os, glob


num_examples = 30000
batch_size = 16
tf.enable_eager_execution()


def load_image(image_path):
    img = tf.io.read_file(image_path)
    img = tf.image.decode_jpeg(img, channels=3)
    img = tf.image.resize(img, (299, 299))
    img = tf.keras.applications.inception_v3.preprocess_input(img)
    return img, image_path


class InceptionEncoder:
    """
    Converts and stores inception embeddings
    """
    def __init__(self, img_paths_list, batch_size=16, npy_dir=None):
        self.img_paths_list = img_paths_list
        self.batch_size = batch_size
        self.npy_dir = npy_dir

    def load_image(self, image_path):
        img = tf.io.read_file(image_path)
        img = tf.image.decode_jpeg(img, channels=3)
        img = tf.image.resize(img, (299, 299))
        img = tf.keras.applications.inception_v3.preprocess_input(img)
        return img, image_path

    def encode(self):
        image_dataset = tf.data.Dataset.from_tensor_slices(self.img_paths_list)
        image_dataset = image_dataset.map(self.load_image,
                        num_parallel_calls=tf.data.experimental.AUTOTUNE).batch(self.batch_size)

        inception = tf.keras.applications.InceptionV3(include_top=False,
                                                weights='imagenet')
        for img, path in image_dataset:
            batch_features = inception(img)
            batch_features = tf.reshape(batch_features,
                                      (batch_features.shape[0], -1, batch_features.shape[3]))

        for bf, p in zip(batch_features, path):
            path_of_feature = p.numpy().decode("utf-8")
            if self.npy_dir:
                path_of_feature = npy_dir+path_of_feature.split("/")[-1]
            np.save(path_of_feature, bf.numpy())


def main():
    annotation_file = open("annotations/captions_train2014.json", 'r')
    annotations = json.load(annotation_file)["annotations"]
    all_captions = []
    all_img_paths = []
    for annotation in annotations:
        caption = "<start>" + annotation["caption"] + "<end>"
        image_id = annotation["image_id"]
        image_path = "train2014/COCO_train2014_" + "%012d.jpg" %image_id
        all_captions.append(caption)
        all_img_paths.append(image_path)
    all_captions, all_img_paths = sklearn.utils.shuffle(all_captions, all_img_paths,
                                  random_state=1)
    train_captions = all_captions[:num_examples]
    train_img_paths = all_img_paths[:num_examples]
    # encode_train = sorted(set(train_img_paths))
    encode_train = glob.glob(os.environ["HOME"] + "/Downloads/*.jpg")
    encoder = InceptionEncoder(encode_train)
    encoder.encode()


if __name__ == "__main__":
    main()
