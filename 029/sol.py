
class RunLengthEncoding:
    @staticmethod
    def encode(string):
        string = list(string)
        char = string.pop(0)
        times = 1
        encoding = ""
        while string:
            this_char = string.pop(0)
            if this_char==char:
                times += 1
            else:
                encoding += "{0}{1}".format(times, char)
                times = 1
            char = this_char
        encoding += "{0}{1}".format(times, char)
        return encoding

    @staticmethod
    def decode(string):
        string = list(string)
        decoding = ""
        while string:
            times = int(string.pop(0))
            char = string.pop(0)
            decoding += times*char
        return decoding


if __name__=='__main__':
    rle = RunLengthEncoding()
    string = "AAAABBBCCDAA"
    encoded = rle.encode(string)
    decoded = rle.decode(encoded)
    print('-->'.join((string, encoded, decoded)))
