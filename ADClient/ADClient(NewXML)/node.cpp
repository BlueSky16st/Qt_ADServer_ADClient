#include "node.h"

#include <QString>
#include <QStringList>

QTime stringToTime(const QString & time)
{	
	QStringList str = time.split(':');
	return QTime(str[0].toInt(), str[1].toInt());
	
}

QString timeToString(const QTime & time)
{
	return time.toString("hh:ss");
	
}

Node::Node(NodeType type)
{
	m_type = type;
	
}

void Node::setType(const NodeType & newType)
{
	m_type = newType;
	
}

NodeType Node::type() const
{
	return m_type;
	
}

MediaNode::MediaNode(NodeType type, const QString & file, const QString & url) : Node(type)
{
	m_file = file;
	m_url = url;
	
}

void MediaNode::setFile(const QString & newFile)
{
	m_file = newFile;
	
}

QString MediaNode::file() const
{
	return m_file;
	
}

void MediaNode::setUrl(const QString & newUrl)
{
	m_url = newUrl;
	
}

QString MediaNode::url() const
{
	return m_url;
	
}

TextNode::TextNode(const QString & text) : Node(Type_text)
{
	m_text = text;
	
}

void TextNode::setText(const QString & newText)
{
	m_text = newText;
	
}

QString TextNode::text() const
{
	return m_text;
	
}

Scene::Scene(const QString & name,
			 const QTime & begin,
			 const QTime & end,
			 const quint16 & interval)
{
	m_name = name;
	m_begin = begin;
	m_end = end;
	m_interval = interval;
	
}

Scene::~Scene()
{
	qDeleteAll(m_nodeList);
	m_nodeList.clear();
	
}

void Scene::setName(const QString & newName)
{
	m_name = newName;
	
}

QString Scene::name() const
{
	return m_name;
	
}

void Scene::setBegin(const QTime & newBegin)
{
	m_begin = newBegin;
	
}

QTime Scene::begin() const
{
	return m_begin;
	
}

void Scene::setEnd(const QTime & newEnd)
{
	m_end = newEnd;
	
}

QTime Scene::end() const
{
	return m_end;
	
}

void Scene::setInterval(const quint16 & newInterval)
{
	m_interval = newInterval;
	
}

quint16 Scene::interval() const
{
	return m_interval;
	
}

void Scene::addNode(Node * newNode)
{
	m_nodeList.append(newNode);
	
}

void Scene::removeNode(int index)
{
	m_nodeList.removeAt(index);
	
}

Node * Scene::node(int index)
{
	return m_nodeList.at(index);
	
}

QList<Node *> Scene::nodeList()
{
	return m_nodeList;
	
}
