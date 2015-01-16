#include "../../include/Graphics/DepthFormat.h"
#include "../../include/Graphics/GraphicsAdapter.h"
#include "../../include/Graphics/GraphicsProfile.h"
#include "../../include/Graphics/SurfaceFormat.h"
#include "../../include/Geometry/Rectangle.h"
#include "../../include/GLEW/glew.h"

//Takes the const GLchar* from glGetString and casts it into an std::string
#define glGetActualString(enum) (std::string{reinterpret_cast<const char*>(glGetString(enum))} + "\0")

namespace YAX
{
	struct GraphicsAdapter::Impl
	{
		DisplayModeCollection _supportedModes;
		std::string _name, _desc, _vendor;
		GLFWmonitor* _handle;

		Impl(std::string name, std::string desc, std::string vend, GLFWmonitor* hnd)
			: _name(name), _desc(desc), _vendor(vend), _handle(hnd)
		{
			//Find and add the supported display modes for this monitor
			i32 modeCount;
			auto modes = glfwGetVideoModes(hnd, &modeCount);
			size_t fixedModeCount = static_cast<size_t>(modeCount);

			for (size_t j = 0; j < fixedModeCount; j++)
			{
				auto vMode = modes[j];

				_supportedModes.emplace_back(DisplayMode(
					{ vMode.redBits, vMode.blueBits, vMode.greenBits },
					Rectangle(0, 0, vMode.width, vMode.height)
				));
			}
		}
		
		~Impl() = default;

		bool IsProfileSupported(GraphicsProfile profile)
		{
			GLint majV;
			glGetIntegerv(GL_MAJOR_VERSION, &majV);

			//Core profile is always available, 
			//Compat is available for versions >= 3.0
			return (profile == GraphicsProfile::HiDef || majV >= 3);
		}

		DisplayMode CurrentDisplayMode() const
		{
			//Don't need to delete this, GLFW manages the memory
			auto vMode = glfwGetVideoMode(_handle);
			return DisplayMode(
				{vMode->redBits, vMode->blueBits, vMode->greenBits},
				Rectangle(0, 0, vMode->width, vMode->height)
			);
		}

		bool IsDefault() const
		{
			return _handle == _defaultAdapter.MonitorHandle();
		}

		bool IsWideScreen() const
		{
			//A widescreen aspect ratio is either 16:9 or 16:10
			float aspRat = CurrentDisplayMode().AspectRatio();
			return aspRat == 1.77f || aspRat == 1.6;
		}
	};

	GraphicsAdapter& GraphicsAdapter::_defaultAdapter = GraphicsAdapter("", "", "", nullptr);
	std::vector<GraphicsAdapter> GraphicsAdapter::_adapters;

	GraphicsAdapter::GraphicsAdapter(std::string name, std::string desc, std::string vend, GLFWmonitor* hnd)
	{
		_impl = std::make_unique<Impl>(name, desc, vend, hnd);
	}

	GraphicsAdapter::~GraphicsAdapter() = default;

	GraphicsAdapter::GraphicsAdapter(GraphicsAdapter&& old)
		: _impl(std::move(old._impl))
	{}

	GraphicsAdapter::GraphicsAdapter(const GraphicsAdapter& old)
		: _impl(new Impl(*old._impl))
	{}

	GraphicsAdapter& GraphicsAdapter::operator=(const GraphicsAdapter& old)
	{
		this->_impl = std::unique_ptr<Impl>(new Impl(*old._impl));
		return *this;
	}

	GraphicsAdapter& GraphicsAdapter::operator=(GraphicsAdapter&& old)
	{
		this->_impl = std::move(old._impl);
		return *this;
	}

	const std::vector<GraphicsAdapter>& GraphicsAdapter::Adapters()
	{
		return _adapters;
	}

	GraphicsAdapter GraphicsAdapter::DefaultAdapter()
	{
		return _defaultAdapter;
	}

	void GraphicsAdapter::FindAdapters()
	{
		//A graphics adapter is essentially a connection to a
		//monitor, so we just find all the monitors on the system
		//and add them to the Adapters vector

		GLFWmonitor* defaultMonitor = glfwGetPrimaryMonitor();
		i32 monitorCount;
		GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
		size_t fixedMonitorCount = static_cast<size_t>(monitorCount);

		//These shouldn't change between adapters unless the monitors
		//are connected to different graphics cards (rare)
		std::string desc = glGetActualString(GL_RENDERER);
		std::string vend = glGetActualString(GL_VENDOR);

		for (size_t i = 0; i < fixedMonitorCount; i++)
		{
			std::string name = glfwGetMonitorName(monitors[i]);
			_adapters.emplace_back(GraphicsAdapter {name, desc, vend, monitors[i] });

			if (monitors[i] == defaultMonitor)
				_defaultAdapter = _adapters[_adapters.size() - 1];
		}
	}

	std::string GraphicsAdapter::Description() const
	{
		return _impl->_desc;
	}

	std::string GraphicsAdapter::DeviceName() const
	{
		return _impl->_name;
	}

	bool GraphicsAdapter::IsDefaultAdapter() const
	{
		return _impl->IsDefault();
	}

	bool GraphicsAdapter::IsWideScreen() const
	{
		return _impl->IsWideScreen();
	}

	GLFWmonitor* GraphicsAdapter::MonitorHandle() const
	{
		return _impl->_handle;
	}

	bool GraphicsAdapter::IsProfileSupported(GraphicsProfile profile) const
	{
		return _impl->IsProfileSupported(profile);
	}

	DisplayMode GraphicsAdapter::CurrentDisplayMode() const
	{
		return _impl->CurrentDisplayMode();
	}

	const DisplayModeCollection& GraphicsAdapter::SupportedDisplayModes() const
	{
		return _impl->_supportedModes;
	}
}