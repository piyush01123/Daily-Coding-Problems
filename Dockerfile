FROM debian:stable-slim
COPY . /DCP
RUN echo "*** Installing gcc (4.9->8) and clang (3.8->6) ***" \
  && DEBIAN_FRONTEND=noninteractive apt-get update \
  && apt-get dist-upgrade -y \
  && echo "deb http://ftp.us.debian.org/debian jessie main contrib non-free" >> /etc/apt/sources.list.d/jessie.list \
  && echo "deb http://ftp.us.debian.org/debian unstable main contrib non-free" >> /etc/apt/sources.list.d/unstable.list \
  && apt-get update \
  && apt-get install -y cmake \
  && apt-get install -y g++-4.9 g++-8 \
  && apt-get install -y clang++-3.8 \
  && apt-get install -y clang++-3.9 \
  && apt-get install -y clang++-4.0 \
  && apt-get install -y clang++-5.0 \
  && apt-get install -y clang++-6.0 \
  && apt-get autoremove --purge -y \
  && apt-get autoclean -y \
  && rm -rf /var/cache/apt/* /tmp/* \
  && echo "Setting g++ 8 as default compiler" \
  && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-8 1
