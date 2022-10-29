#include <iostream>
#include <ctime>

void dateWithMonth(time_t date)
{
	switch (tm *dateTm = localtime(&date); dateTm->tm_mon)
	{
		case 0:
			std::cout << dateTm->tm_mday << " stycznia " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 1:
			std::cout << dateTm->tm_mday << " lutego " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 2:
			std::cout << dateTm->tm_mday << " marca " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 3:
			std::cout << dateTm->tm_mday << " kwietnia " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 4:
			std::cout << dateTm->tm_mday << " maja " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 5:
			std::cout << dateTm->tm_mday << " czerwca " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 6:
			std::cout << dateTm->tm_mday << " lipca " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 7:
			std::cout << dateTm->tm_mday << " sierpnia " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 8:
			std::cout << dateTm->tm_mday << " września " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 9:
			std::cout << dateTm->tm_mday << " października " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 10:
			std::cout << dateTm->tm_mday << " listopada " << 1900 + dateTm->tm_year << std::endl;
			break;
		case 11:
			std::cout << dateTm->tm_mday << " grudnia " << 1900 + dateTm->tm_year << std::endl;
			break;
	
		default:
			break;
	}
}

int main()
{
	time_t now = time(0);
	dateWithMonth(now);

	return 0;
}