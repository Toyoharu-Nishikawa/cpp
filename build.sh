#sudo rm -rf work3/build
docker compose exec cpp cmake --preset linux-debug
docker compose exec cpp cmake --build --preset linux-debug
docker compose exec cpp ctest --preset linux-debug



#docker compose exec cpp cmake --preset windows-release 
#docker compose exec cpp cmake --build --preset windows-release

