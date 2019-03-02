Quick Docker image for spdrd
---------------------------

Build docker image:
   
    docker/build.sh

Push docker image:

    docker/push.sh

Pull spdrcore/spdr:latest from docker hub  at [spdr-dockerhub](https://hub.docker.com/r/spdrcore/spdr/)

    sudo docker pull spdrcore/spdr
    
Run docker image

    sudo docker run spdrcore/spdr

Build docker for spdrd
----------
A Docker configuration with spdrd node by default.

    sudo apt install apt-transport-https ca-certificates curl software-properties-common; curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -; sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"; sudo apt-get update; sudo apt install docker-ce   
---------------------------------------------------        
    
    mkdir spdr-mounted-data
    docker run --name spdr -d \
     --env 'SPDR_RPCUSER=rpciser' \
     --env 'SPDR_RPCPASSWORD=rpcpassword' \
     --env 'SPDR_TXINDEX=1' \
     --volume ~/spdr-mounted-data:~/.spdr \
     -p 53616:53616 \
     --publish 53616:53616 \
     spdrcore/spdr
----------------------------------------------------
Logs

    docker logs -f spdr

----------------------------------------------------

## Configuration

Set your `spdr.conf` file can be placed in the `spdr-mounted data` dir.
Otherwise, a default `spdr.conf` file will be automatically generated based
on environment variables passed to the container:

| name | default |
| ---- | ------- |
| BTC_RPCUSER | rpcuser |
| BTC_RPCPASSWORD | rpcpassword |
| BTC_RPCPORT | 53616 |
| BTC_RPCALLOWIP | ::/0 |
| BTC_RPCCLIENTTIMEOUT | 30 |
| BTC_DISABLEWALLET | 1 |
| BTC_TXINDEX | 0 |
| BTC_TESTNET | 0 |
| BTC_DBCACHE | 0 |
| BTC_ZMQPUBHASHTX | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBHASHBLOCK | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBRAWTX | tcp://0.0.0.0:28333 |
| BTC_ZMQPUBRAWBLOCK | tcp://0.0.0.0:28333 |


## Daemonizing

If you're daemonizing is to use Docker's 
[Daemonizing](https://docs.docker.com/config/containers/start-containers-automatically/#use-a-restart-policy),
but if you're insistent on using systemd, you could do something like

```
$ cat /etc/systemd/system/spdrd.service

# spdrd.service #######################################################################
[Unit]
Description=Spider
After=docker.service
Requires=docker.service

[Service]
ExecStartPre=-/usr/bin/docker kill spdr
ExecStartPre=-/usr/bin/docker rm spdr
ExecStartPre=/usr/bin/docker pull spdrcore/spdr
ExecStart=/usr/bin/docker run \
    --name spdr \
    -p 53616:53616 \
    -p 53616:53616 \
    -v /data/spdrd:/root/.spdr \
    spdrcore/spdr
ExecStop=/usr/bin/docker stop spdr
```
