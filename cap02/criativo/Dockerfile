FROM debian:bookworm-slim
RUN apt update && apt install -y \
    gcc \
    make \
    libgl-dev \
    libx11-dev \
    libxcursor-dev \
    libxrandr-dev \
    libxi-dev \
    libxinerama-dev \
    libxxf86vm-dev \
    libasound-dev \
    libc6-dev \
    pkg-config
WORKDIR /usr/src/app
COPY . .
RUN make
