
import numpy as np
import cv2
import dlib


net = cv2.dnn.readNetFromCaffe('deploy.prototxt.txt', 'res10_300x300_ssd_iter_140000.caffemodel')


def detect_faces(frame, thresh=0.5):
	h, w = frame.shape[:2]
	blob = cv2.dnn.blobFromImage(cv2.resize(frame, (300, 300)), 1.0,\
		   (300, 300), (104.0, 177.0, 123.0))
	net.setInput(blob)
	detections = net.forward()
	mod_frame = frame.copy()
	for i in range(0, detections.shape[2]):
		confidence = detections[0, 0, i, 2]
		if confidence < thresh:
			continue
		box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
		startX, startY, endX, endY = box.astype("int")
		text = "{:.2f}%".format(confidence * 100)
		y = startY - 10 if startY - 10 > 10 else startY + 10
		mod_frame = cv2.rectangle(mod_frame, (startX, startY), (endX, endY),
			(0, 0, 255), 2)
		mod_frame = cv2.putText(mod_frame, text, (startX, y),
			cv2.FONT_HERSHEY_SIMPLEX, 0.45, (0, 0, 255), 2)
	return mod_frame


def detect_faces_dlib(img):
	detector = dlib.get_frontal_face_detector()
	rects = detector(img, 1)
	for i, rect in enumerate(rects):
		print('Face Number', i)
		tl = rect.left(), rect.top()
		br = rect.right(), rect.bottom()
		print('TL BR', tl, br)
		img = cv2.rectangle(img, tl, br, (0, 255, 0), 3)
	return img


def test():
	img = cv2.imread('img.jpg')
	frame1 = detect_faces(img)
	cv2.imwrite('caffe.jpg', frame1)
	frame2 = detect_faces_dlib(img_c)
	cv2.imwrite('dlib.jpg', frame2)


if __name__=='__main__':
	test()
