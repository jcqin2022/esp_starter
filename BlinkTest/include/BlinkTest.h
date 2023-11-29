#ifndef __BLINKTEST__
#define __BLINKTEST__

class BlinkTest
{
public:
	void setup();
	void loop();

	BlinkTest();
	void printLoopTimes();
	void blink_error();
	void blink_warning();
	void blink_success();
	void blink_inprogress();
private:
	int count;
};

#endif //__BLINKTEST__
