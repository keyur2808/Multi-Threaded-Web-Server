all:
	g++ -static -o myhttpd main.cpp network.cpp getpt.cpp dir.cpp -lpthread
