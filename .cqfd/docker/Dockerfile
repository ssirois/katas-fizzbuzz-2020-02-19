FROM gcc:6

RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -y -q --no-install-recommends \
    cmake \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN cd /tmp && \
    git clone https://github.com/cgreen-devs/cgreen && \
    cd ./cgreen && \
    git checkout 1.2.0 && \
    make && \
    make test && \
    make install && \
    rm -rf /tmp/cgreen
