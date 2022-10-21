#include "abpch.h"
#include "LayerStack.h"

namespace Above
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	/// <summary>
	/// Always pushes layers at the beginning of the stack
	/// </summary>
	/// <param name="layer"></param>
	void LayerStack::PushLayer(Layer* layer)
	{
		//Changing element the iterator is pointing at
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	/// <summary>
	/// Always pushes overlays at the end of the stack,
	/// so they get rendered the last (on top of everything else)
	/// </summary>
	/// <param name="overlay"></param>
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;			//Changing element the iterator is pointing at
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}
