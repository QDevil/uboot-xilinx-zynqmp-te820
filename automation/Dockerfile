FROM python:3

## Fix jenkins user setup (https://stackoverflow.com/a/56083736/13372).
RUN groupadd -g 1000 jenkins \
    && useradd -lm -u 1000 -g 1000 jenkins \
    && adduser jenkins sudo \
    && mkdir -p /home/jenkins/workspace \
    && chown jenkins:jenkins /home/jenkins/workspace

RUN apt-get update \
    && apt-get install -y \
       bc \
       curl \
       sudo \
    && rm -rf /var/lib/apt/lists/*

## And set a random password (846e02a00536464190bb15d9a27908ff) so that it is
## possible to sudo inside the container (for debugging).
RUN (echo 'jenkins:846e02a00536464190bb15d9a27908ff' | chpasswd)
