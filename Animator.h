#pragma once
#include<chrono>
#include <array>
#include <functional>

#define EASING_LIST(_) \
	/*Linear*/	 _(Linear) \
	/*Quadratic*/_(InQuad)	_(OutQuad)	_(InOutQuad)	\
	/*Cubic*/	 _(InCubic) _(OutCubic) _(InOutCubic)	\
	/*Quart*/	 _(InQuart) _(OutQuart) _(InOutQuart)	\
	/*Quint*/	 _(InQuint) _(OutQuint) _(InOutQuint)	\
	/*Sine*/	 _(InSine)	_(OutSine)	_(InOutSine)	\
	/*Expo*/	 _(InExpo)	_(OutExpo)	_(InOutExpo)	\
	/*Circular*/ _(InCirc)	_(OutCirc)	_(InOutCirc)

using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;

class ChezzeAnimator
{

public:
#define GEN_ENUM(name) name,
	enum AnimType
	{
		EASING_LIST(GEN_ENUM)
		AnimTypeCount
	};
#undef GEN_ENUM

	ChezzeAnimator(float* value, float to, AnimType anim, float durationMs);

	void setToValue(float to);
	void setToValue(float to, AnimType anim);
	void setStartValue(float start_value);
	void setType(AnimType anim);
	void setSpeed(float speedMs);


	void start();
	void stop();

	void update();

	bool isStarted();
	void setCompleteCallback(std::function<void()> cb)
	{
		m_completed_callback = cb;
	}
private:
	using EasingFunc = float(*)(float);
	static const std::array<EasingFunc, AnimTypeCount> easing_table;

	bool m_started;
	float* m_value;
	float m_start_value;
	float m_to_value;
	AnimType m_anim_type;

	float m_durationMs;
	TimePoint m_start_time;

	std::function<void()> m_completed_callback;
};