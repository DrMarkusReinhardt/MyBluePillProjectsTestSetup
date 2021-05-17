/* Event.h
 *
 *
 * @author: Dr. Markus Reinhardt
 * @date: April 2021
 *
*/
#pragma once

namespace MR_GUI_LIB
{

template<typename ParameterType>
class Event
{
public:
  Event(String initId) : m_id(initId) 
  {}
  
  Event(String initId, ParameterType initParameter) : m_parameter(initParameter)
  {};
  
  String getId()
  {
    return m_id;
  }
  
  void setParameter(ParameterType parameter) 
  {
    m_parameter = parameter;
  }
  
  ParameterType getParameter()
  {
    return m_parameter;
  }
  
private:
  String m_id;
  ParameterType m_parameter;
};

} // namespace MR_GUI_LIB