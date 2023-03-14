# % ctf_lecture_2: docker

## % video ([click](https://youtu.be/rNZsoBAQwYk))

[![video](https://img.youtube.com/vi/rNZsoBAQwYk/0.jpg)](https://youtu.be/rNZsoBAQwYk)

## % debriefing

1. docker is a containerization tool used to run applications in isolated environments

- docker commands are executed in the terminal
  - `docker run` is used to run a container
  arguments:
    - `-it` runs the container in interactive mode
    - `-p` maps a port on the host to a port in the container
    - `-v` mounts a volume on the host to a directory in the container
    - `--rm` removes the container after it exits
    - `--restart` restarts the container if it exits (argument: `always`, `on-failure`, `unless-stopped`, `no`)

  - `docker ps` shows running containers
  arguments:
    - `-a` shows all containers
    - `-q` shows only container IDs
    - `-f` filters containers by a condition
    - `--format` formats the output
    - `-s` shows container sizes

  - `docker images` shows available images
  arguments:
    - `-a` shows all images
    - `-q` shows only image IDs
    - `-f` filters images by a condition
    - `--format` formats the output
    - `-s` shows image sizes

  - `docker exec` is used to run a command in a running container
  arguments:
    - `-it` runs the command in interactive mode
    - `-e` sets an environment variable
    - `-u` sets the user
    - `-w` sets the working directory

  - `docker build` is used to build an image from a Dockerfile
  arguments:
    - `-t` sets the image tag
    - `--build-arg` sets a build argument
    - `--no-cache` disables the cache
    - `--pull` pulls the latest version of the base image
    - `--target` sets the target build stage

  - `docker pull` is used to pull an image from a registry
  arguments:
    - `-a` pulls all tags
    - `-q` pulls the image quietly
    - `--disable-content-trust` disables content trust (skips image verification) (defaults to true)
    - `--platform` sets the platform if server is multi-platform capable

  - `docker push` is used to push an image to a registry
  arguments:
    - `-a` pushes all tags
    - `-q` pushes the image quietly
    - `--disable-content-trust` disables content trust (skips image verification) (defaults to true)

- docker compose is a tool for defining and running multi-container docker applications

  - `docker-compose up` is used to start the application
  arguments:
    - `-d` runs the application in detached mode
    - `--build` builds the application before starting
    - `--force-recreate` recreates the containers even if they haven't changed
    - `--no-deps` doesn't start linked services
    - `--no-recreate` doesn't recreate containers that already exist
    - `--no-start` doesn't start the services
    - `--remove-orphans` removes containers for services not defined in the compose file
    - `--scale` sets the number of containers to start for a service

  - `docker-compose down` is used to stop the application
  arguments:
    - `-v` removes the volumes associated with the containers
    - `--rmi` removes the images associated with the containers
    - `--remove-orphans` removes containers for services not defined in the compose file
    - `--timeout` sets the shutdown timeout in seconds

  - `docker-compose exec` is used to run a command in a running container
  arguments:
    - `-T` runs the command in non-interactive mode
    - `-d` runs the command in detached mode
    - `-e` sets an environment variable
    - `-u` sets the user
    - `-w` sets the working directory

  - `docker-compose build` is used to build the application
  arguments:
    - `--no-cache` disables the cache
    - `--pull` pulls the latest version of the base image
    - `--parallel` builds images in parallel
    - `--force-rm` removes intermediate containers after a successful build
    - `--compress` compresses the build context using gzip
    - `--build-arg` sets a build argument

  - `docker-compose pull` is used to pull the images for the services
  arguments:
    - `--ignore-pull-failures` pulls what it can and ignores images with pull failures
    - `--parallel` pulls images in parallel
    - `--include-deps` pulls dependent services

  - `docker-compose push` is used to push the images for the services
  arguments:
    - `--ignore-push-failures` pushes what it can and ignores images with push failures

  - `docker-compose logs` is used to show the logs for the services
  arguments:
    - `-f` follows the logs
    - `-t` shows timestamps
    - `--tail` shows the last n lines of logs
    - `--no-color` disables color output
    - `--no-log-prefix` disables prefixing the log output with service and container names
    - `--until` shows logs until a timestamp

## % examples

### `docker run` a postgresql container

```bash
docker run -it --rm -p 5432:5432 -e POSTGRES_PASSWORD=postgres --restart always postgres
```

### `docker run` a redis container

```bash
docker run -it --rm -p 6379:6379 --restart unless-stopped redis
```

### `docker compose` postgres and redis example

```yaml
version: '3'

services:
  postgres:
  image: postgres
    restart: always
    environment:
      POSTGRES_PASSWORD: postgres
    ports:
      - 5432:5432

  redis:
    image: redis
    restart: unless-stopped
    ports:
      - 6379:6379
```

### `docker compose` build image example

```yaml
version: '3'

services:
  app:
    build:
      context: .
      dockerfile: Dockerfile  # Can be omitted if the file is named Dockerfile
      args:
        - NODE_ENV=production
    restart: always
    ports:
      - 3000:3000
```

## % frequently_asked_questions

### q: docker commands refuse to run. what gives?

a: docker needs special permissions to execute your commands. if you see "permission denied" errors, you need to add your user to the docker group. you can do this by running `sudo usermod -aG docker $USER` and then logging out and back in. if in a hurry, just run `newgrp docker` to update your groups in the running terminal without logging out.

p.s. you can also run docker commands with `sudo`, but this is not recommended.
p.p.s.: `docker` group de-facto is a root group. do not give arbitrary users access to it.

if docker is not running (you're observing "docker: command not found" errors), you need to install it. see the installation section for more details. if it is installed, you may need to start it with `sudo systemctl enable --now docker`.

### q: what is the difference between docker and docker compose?

a: docker is a containerization tool used to run applications in isolated environments. docker compose is a tool for defining and running multi-container docker applications

### q: what is the difference between docker run and docker exec?

a: docker run is used to run a container. docker exec is used to run a command in a running container

### q: what is the difference between docker build and docker pull?

a: docker build is used to build an image from a Dockerfile. docker pull is used to pull an image from a registry

### q: what is the difference between docker-compose down and docker-compose stop?

a: docker-compose down is used to stop the application and remove all stopped containers. docker-compose stop is used to stop the services, but keep them in the list of containers (`docker compose ps -a` or `docker ps -a`)

### q: how to run a docker container in the foreground/background?

a: use the `-d` flag to run the container in the background. use the `-it` flag to run the container in the foreground

### q: how to restart a container?

a: use the `--restart` flag to restart a container. the value can be `no`, `on-failure`, `always`, `unless-stopped`, or `on-failure:n` where n is the number of times to retry. to start a container that has been stopped, use `docker start <container name or id>`

## homework

- install a gnu/linux distribution (recommended: [endeavouros](https://endeavouros.com/), [debian](https://debian.org/))
- install [docker](https://docs.docker.com/engine/install/)
- install [docker compose](https://docs.docker.com/compose/install/) (only if `docker compose` is not available; then use `docker-compose` after installation)
- run a postgresql container with `docker run` in the foreground and instruct docker to automatically remove it when it exits
- run a redis container with `docker run` in the background and instruct docker to restart it unless it is stopped; then stop and remove it
- create a `docker-compose.yml` file with a postgresql and elasticsearch service; execute it, check the logs, and then stop it
- create a new repository on github under your personal account, name it "ctf-course", then push all commands you used to the repository under `lessons/docker/commands.sh` and all docker-compose.yml files under `lessons/docker/docker-compose.<task name>.yml`
- ask all questions you have in our telegram channel!
