/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        MTA10_Server/mods/deathmatch/logic/CTrainTrack.cpp
*  PURPOSE:     Train Node class
*  DEVELOPERS:  Cazomino05 <Cazomino05@gmail.com>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/
#include "StdInc.h"

CTrainTrack::CTrainTrack(CTrainTrackManager* pManager, const std::vector<STrackNode>& nodes, bool linkLastNodes, CElement* pParent, CXMLNode* pNode, bool default)
    : CElement(pParent, pNode), m_pManager(pManager)
{
    m_iType = CElement::TRAINTRACK;
    SetTypeName("train-track");

    m_LinkLastNodes = linkLastNodes;
    m_Nodes = nodes;
    m_Default = default;
}

CTrainTrack::~CTrainTrack()
{
    m_pManager->DestroyTrainTrack(this);
}

bool CTrainTrack::SetTrackNodePosition(uint nodeIndex, const CVector& position)
{
    if (nodeIndex >= m_Nodes.size())
        return false;

    auto& node = m_Nodes[nodeIndex];
    node.position = position;
    return true;
}

bool CTrainTrack::GetTrackNodePosition(uint nodeIndex, CVector& position)
{
    if (nodeIndex >= m_Nodes.size())
        return false;

    auto& node = m_Nodes[nodeIndex];
    position = node.position;
    return true;
}
