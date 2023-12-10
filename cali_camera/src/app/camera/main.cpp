#include "hik_camera.hpp"
#include "opencv2/opencv.hpp"

void save(cv::String path, std::vector<cv::String> dict) {
	cv::FileStorage fs(path,
					   cv::FileStorage::WRITE | cv::FileStorage::FORMAT_XML);
	
	assert(fs.isOpened());
	fs.write("images", dict);
	
	fs.release();
}

int main(int, char **) {
	HikCamera cam(0, 640, 480);
	std::vector<cv::String> dict;
	int id = 0;
	bool grab = false;
	cv::VideoWriter vw;
	cv::Mat frame;
	
	while (true) {
		frame = cam.GetFrame();
		if (frame.empty()) continue;
		if (!vw.isOpened()) {
			vw.open("../../../../out.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 25, frame.size());
		}
		
		cv::imshow("show", frame);
		
		if (grab && vw.isOpened()) {
			vw.write(frame);
		}
		
		switch (cv::waitKey(10)) {
			case ' ': {
				cv::String path = cv::format("../../../../images/%d.png", id++);
				cv::imwrite(path, frame);
				dict.push_back(path);
			}
				break;
			case 'v':
				grab = !grab;
				break;
			case 'q':{
				if (dict.size() > 0){
					save("../../../../images/VID5.xml", dict);
				}
				vw.release();
				return 0;
			}
			default:
				break;
		}
	}
}
