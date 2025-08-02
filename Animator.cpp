#include"Animator.h"
#include "easing.h"

#if __cplusplus >= 202002L
//#include <cmath>
using std::lerp;
#else

template<typename T>
constexpr T lerp(const T& a, const T& b, float t) {
	return a + (b - a) * t;
}
#endif


ChezzeAnimator::ChezzeAnimator(float* value, float to, AnimType anim, float durationMs) :
	m_start_value(*value), m_value(value), m_anim_type(anim), m_started(false), m_to_value(to), m_durationMs(durationMs)
{

}

void ChezzeAnimator::setToValue(float to, AnimType anim)
{
	m_anim_type = anim;
	setToValue(to);
}

void ChezzeAnimator::setToValue(float to)
{
	m_to_value = to;
}

void ChezzeAnimator::setStartValue(float start_value)
{
	m_start_value = start_value;
}

void ChezzeAnimator::start()
{
	if (m_started)
		return;

	m_started = true;
	m_start_time = Clock::now();
}

void ChezzeAnimator::stop()
{
	if (!m_started)
		return;

	m_start_value = *m_value;
	m_started = false;
}

void ChezzeAnimator::update()
{
	if (!m_started)
		return;

	TimePoint now = Clock::now();
	float elapsedMs = std::chrono::duration<float, std::milli>(now - m_start_time).count();

	float t = elapsedMs / m_durationMs;
	if (t > 1.0f) t = 1.0f;

	float easedT = easing_table[m_anim_type](t);

	*m_value = lerp(m_start_value, m_to_value, easedT);

	if (t == 1.0) 
	{
		stop();
		if (m_completed_callback)
			m_completed_callback();
	}
}

bool ChezzeAnimator::isStarted()
{
	return m_started;
}

void ChezzeAnimator::setType(AnimType anim)
{
	if (anim != m_anim_type)
		m_anim_type = anim;
}

void ChezzeAnimator::setSpeed(float speedMs)
{
	m_durationMs = speedMs;
}

#define GEN_TABLE(name) Easing::name,

const std::array<ChezzeAnimator::EasingFunc, ChezzeAnimator::AnimTypeCount>
ChezzeAnimator::easing_table = {
	EASING_LIST(GEN_TABLE)
};

#undef GEN_TABLE
#undef EASING_LIST