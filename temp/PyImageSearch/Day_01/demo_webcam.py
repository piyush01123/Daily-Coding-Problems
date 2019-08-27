
import cv2
from face_detection import detect_faces


class FaceDetector:
    def __init__(self, src=0):
        self.src = src

    def stream(self):
        self.src_stream = cv2.VideoCapture(self.src)
        while True:
            _, frame = self.src_stream.read()
            detected = detect_faces(frame)
            cv2.imshow('Face Detector', detected)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        self.src_stream.release()
        cv2.destroyAllWindows()


if __name__=='__main__':
    face_detector = FaceDetector()
    face_detector.stream()
