#FROM debian:stretch
FROM ubuntu:18.04
LABEL maintainer="The Spidercore Developers <216k155@spidervps.net>"
LABEL description="Dockerised Spidercore, built from Travis"

RUN apt-get update && apt-get install -y software-properties-common unzip
RUN apt-get install -y wget

RUN wget https://github.com/SPDR-Core/spdr/releases/download/v5.2.3/spdr-qt-linux-18.zip
RUN unzip spdr-qt-linux-18.zip
RUN cp spdrd /usr/local/bin

VOLUME ["/opt/spdr"]

EXPOSE 53616
EXPOSE 53616
EXPOSE 9777
EXPOSE 9777

CMD ["spdrd", "--conf=/opt/spdr/spdr.conf", "--printtoconsole"]