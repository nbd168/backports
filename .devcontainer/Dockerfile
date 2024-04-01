FROM ubuntu:22.04

RUN apt update && \
	apt install -y git coccinelle build-essential python3 python3-pip python-is-python3 flex bison libelf1 libelf-dev && \
	rm -rf /var/lib/apt/lists/*

RUN pip install pyzstd zstandard

RUN git clone https://github.com/hauke/backports.git

RUN /backports/devel/backports-update-manager --yes --no-git-update && \
	rm -rf /ksrc-backports/debs/

WORKDIR /
