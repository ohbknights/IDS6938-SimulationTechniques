#ifndef AGENTDISPLAY_H
#define AGENTDISPLAY_H

#include "Transformation.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
using namespace std;

class Joint
{
public:
	Joint(const unsigned int& id, const vec3& offset);
	unsigned int m_id;
	vec3 m_offset;
	vector<Joint*> m_pChildren;
	Joint* m_pParent;

	static void AttachJoints(Joint* pParent, Joint* pChild);
};

class AgentDisplay
{
public:
	static void CreateDrawList();
	static GLuint listNames;
private:
	static void DrawSkeleton(Joint* pRootJoint, float* pJointAngles);
	static void DrawBodyParts(Joint* pJoint, float* pJointAngles);
	static void CreateSkeleton(vector<Joint*>& pJointList);
};

const float rootHeight[43] = {98.18f, 98.11f, 97.86f, 97.33f, 96.90f, 96.45f, 95.76f, 94.81f, 93.88f, 93.19f, 
							  92.92f, 92.83f, 92.93f, 93.32f, 93.92f, 94.74f, 95.57f, 96.18f, 96.35f, 96.08f,
							  95.52f, 95.07f, 95.17f, 95.70f, 96.06f, 96.26f, 96.15f, 95.62f, 94.80f, 93.94f,
							  93.28f, 93.20f, 93.32f, 93.47f, 93.66f, 94.11f, 94.90f, 95.92f, 96.92f, 97.78f,
							  98.39f, 98.64f, 98.62f};

const unsigned int totalFrames = 43;

#endif //AGENTDISPLAY_H