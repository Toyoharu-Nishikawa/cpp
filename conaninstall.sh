export ENV_UID=$(id -u)
export ENV_GID=$(id -g)
docker compose run --rm cpp ./conan_install.sh
#docker compose run --rm cpp bash ./run.sh
#docker compose run --rm cpp echo "hello" 
