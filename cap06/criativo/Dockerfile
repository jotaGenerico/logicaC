FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

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
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app

# Copia todo o conteúdo de cap06/criativo para dentro do container
COPY . .

# Compila todos os exercícios (6.1 a 6.5) durante o build
RUN make

CMD ["make"]
